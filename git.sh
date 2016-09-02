#!/bin/bash
##
echo "git operation.........."

echo "xx $#"

if [ $# -gt 1 ]
then
    echo 'input error'
    exit 
fi

if [ $1 = 'push' ]
then
    echo 'push,please input commit -m '
    read  msgcommit
    git  add -A
    git commit -m  ${msgcommit}
    git push origin master
else 
    echo 'pull'
    git pull origin master
fi
