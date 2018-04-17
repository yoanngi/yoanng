if [ "$#" -ne 2 ] ; then
	echo "usage: sh $0 [user] [ip-address]"
	exit 1
fi

USR=$1
IP=$2

ssh-keygen -t rsa
scp ~/.ssh/id_rsa.pub $USR@$IP:/root/.ssh/authorized_keys
