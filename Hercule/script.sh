if [ "$#" -ne 2 ] ; then
	echo "usage: sh $0 user ip-address"
	exit 1
fi
https://www.generation-linux.fr/index.php?post/2008/02/26/79-se-connecter-en-ssh-sans-demande-de-mot-de-passe

SSH_USR=$1
SSH_IPADDR=$2

ssh-keygen -t rsa
ssh $SSH_USR@$SSH_IPADDR mkdir -p .ssh
cat ~/.ssh/id_rsa.pub | ssh $SSH_USR@$SSH_IPADDR 'cat >> .ssh/authorized_keys'
ssh $SSH_USR@$SSH_IPADDR "chmod 700 .ssh; chmod 640 .ssh/authorized_keys"
