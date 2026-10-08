#!/usr/bin/env bash
# This file exists to check g++ make cmake on PATH / Catch2 JUCE submodule tags in CPP_DRILLS
# SOLUTION/TESTS/test_main.cpp - runs it through std::system()
# usage: bash SOURCE/check_dependencies.sh ~/REPOS/_DRILLS/CPP_DRILLS
set -uo pipefail

failures=0

report_failure()
{
    printf 'MISSING %s\n' "$1"
    failures=$((failures + 1))
}

check_tool()
{
    local tool="$1"
    if ! command -v "$tool" >/dev/null 2>&1; then
        report_failure "$tool is not on PATH"
    fi
}

check_submodule_tag()
{
    local submodule_dir="$1"
    local wanted_tag="$2"
    local found_tag
    if [ ! -e "$submodule_dir/.git" ]; then
        report_failure "$submodule_dir is not a git checkout"
        return
    fi
    found_tag="$(git -C "$submodule_dir" describe --tags --exact-match 2>/dev/null)"
    if [ "$found_tag" != "$wanted_tag" ]; then
        report_failure "$submodule_dir is at tag '$found_tag' and the drills need $wanted_tag"
    fi
}

if [ "$#" -ne 1 ]; then
    printf 'usage: bash SOURCE/check_dependencies.sh ~/REPOS/_DRILLS/CPP_DRILLS\n' >&2
    exit 2
fi

repo_dir="$1"

check_tool g++
check_tool make
check_tool cmake
check_submodule_tag "$repo_dir/SUBMODULES/Catch2" v3.9.1
check_submodule_tag "$repo_dir/SUBMODULES/JUCE" 9.0.3

if [ "$failures" -ne 0 ]; then
    exit 1
fi
exit 0
