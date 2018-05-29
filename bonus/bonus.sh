#!/bin/bash

sed "s|O|$(echo "\033[0;32mO\033[0m")|g; \
s|X|$(echo "\033[0;31mX\033[0m")|g; \
s|o|$(echo "\033[1;32mo\033[0m")|g; s|x|$(echo "\033[1;31mx\033[0m")|g"