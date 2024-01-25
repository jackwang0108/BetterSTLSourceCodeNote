#!/bin/bash

runSTL() {
    local program_dir="$1"
    local program_name="$2"
    local program_path="./bin/$program_dir/$program_name"

    if [ -x "$program_path" ]; then
        "$program_path"
    else
        echo "Error: Program $program_name not found in directory $program_dir"
    fi
}

# 补全脚本
_runSTL_completion() {
    local cur prev

    COMPREPLY=()
    cur="${COMP_WORDS[COMP_CWORD]}"
    prev="${COMP_WORDS[COMP_CWORD-1]}"

    if [[ $COMP_CWORD -eq 1 ]]; then
        # 第一次按Tab，补全子目录名称
        COMPREPLY=( $(compgen -W "$(\ls -d ./bin/*/ | xargs -n 1 basename)" -- "$cur") )
    elif [[ $COMP_CWORD -eq 2 ]]; then
        # 第二次按Tab，补全可执行文件名
        local program_dir="${COMP_WORDS[1]}"
        COMPREPLY=( $(compgen -W "$(\ls -p ./bin/$program_dir | grep -v /)" -- "$cur") )
    fi
}

complete -F _runSTL_completion runSTL
