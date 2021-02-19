#!/bin/sh
echo
echo "USER SEARCH"
echo "Developer: Vladimir Kolov"
echo "With this program you can:"
echo "1) Find the user"
echo "2) Show user's UID"
echo "3) Find the groups to which he belongs"
echo
answer() 
{
    echo "Repeat? (Y/n)"
    read item
        case "$item" in
                y|Y) echo "OK, repeat..."
                echo
                    ;;
            n|N) echo "OK, exit..."
                echo
                exit 0
                    ;;
            *) echo "ERROR"
                echo
                answer
                    ;;
        esac
}
while true;
do
    echo -n "Enter username: "
    read user
    if cat /etc/shadow | grep "$user";
        then
        id -u "$user"
        id -ng "$user"
        id -nG "$user"
        answer
        continue	
    else echo "User is not found"
    fi
answer
done
echo