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
    flag=0
    while read line
    do
        flag=1
        echo "ID: $i Data: $line"
        i=$((i+1))
    done < $FILE

    if [ $flag -eq 0 ]
    then
        echo "No records found"
    fi
}

insert () {
    read -p "Enter name: " name
    read -p "Enter phone number: " phone_no
    echo "$name - $phone_no" >> $FILE

    read -p "Add more records or exit: (y/n)" op
    if [ "$op" = "y" ]
    then
        insert
    fi
}

delete () {
    read -p "Enter the name to be deleted: " name
    result=`sed -i "/$name - */d" $FILE`
}

find () {
    read -p "Enter the name: " name
    result=`grep -i "$name" "$FILE"`
    if test -z "$result"
    then
        echo "Not found"
    else
        echo "Found record - $result"
    fi
}

modify () {
    read -p "Enter the name to update: " name
    read -p "Enter updated phone number: " number
    result=`sed -i "/$name - */d" $FILE`
    echo "$name - $number" >> $FILE
}

while [ $OP -ne 07 ]
do

    echo "\n1.Create 2.View 3.Insert 4.Delete 5.Modify 6. Find 7. Exit"
    read -p "Enter choice: " OP

    case $OP in
    1) create
    ;;
    2) view
    ;;
    3) insert
    ;;
    4) delete
    ;;
    5) modify
    ;;
    6) find
    ;;
    7) echo "Exit"
    ;;
    *) echo "default"
    ;;
    esac
done