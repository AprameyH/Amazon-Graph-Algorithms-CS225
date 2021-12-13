#!/bin/bash

# This is a shell script to run all tests sequentially.

TEST_PARSING="test-parsing"
TEST_ALGORITHM="test-algorithm"

echo "Testing Parsing"
cd parsing/
./$TEST_PARSING
cd ..

echo "Testing algorithm"
cd algorithm/
./$TEST_ALGORITHM
cd ..
