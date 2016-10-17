#!/bin/sh

echo "Disabling exec shield"
sudo sysctl -w kernel.exec-shield=0
sudo sysctl -w kernel.randomize_va_space=0
execstack -s ./vulnerable-code
