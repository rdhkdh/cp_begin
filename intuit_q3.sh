#!/usr/bin/env bash

perform_operation()
{
    local line="$1"
    local result=0

    #extract operator
    local op=""
    if echo "$line" | grep -qiw "sum"; then
        op="sum"
    elif echo "$line" | grep -qiw "difference"; then
        op="difference"
    elif echo "$line" | grep -qiw "multiply"; then
        op="multiply"
    elif echo "$line" | grep -qiw "divide"; then
        op="divide"
    fi

    #extract the 2 integers
    local nums=($(echo "$line" | grep -oE '\-?[0-9]+'))
    local num1=${nums[0]}
    local num2=${nums[1]}

    #perform operation
    case "$op" in
    sum)        result=$((num1 + num2)) ;;
    difference) result=$((num1 - num2)) ;;
    multiply)   result=$((num1 * num2)) ;;
    divide)     result=$((num1 / num2)) ;;
    esac
}