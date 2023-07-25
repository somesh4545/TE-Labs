#!/bin/sh

OP=0
FILE="new.txt"

create () {
    echo "\nEnter file name: "
    read FILE
    touch  $FILE
}

view () {
    i=1
    while read line
    do
        echo "ID: $i Data: $line"
        i=$((i+1))
    done < $FILE
}

insert () {
    echo "Enter name: "
    read name
    echo "Enter phone number: "
    read phone_no
    echo "$name - $phone_no" >> $FILE

    echo "Add more records or exit: (y/n)"
    read op
    if [ "$op" = "y" ]
    then
        insert
    fi
}

delete () {
    echo "Enter the name to be deleted: "
    read name

    while read line
    do
        IFS='-'
        read -a arr <<< "$line"
        echo "${arr[0]}"
        # if [[ $line =~ "$name" ]]
        # then
        #     echo "Found details"
        # fi
    done < $FILE
}

while [ $OP -ne 06 ]
do

    echo "\n1.Create 2.View 3.Insert 4.Delete 5.Modify 6. Exit"
    read OP

    case $OP in
    1) create
    ;;
    2) view
    ;;
    3) insert
    ;;
    4) delete
    ;;
    6) echo "Exit"
    ;;
    *) echo "default"
    ;;
    esac
done