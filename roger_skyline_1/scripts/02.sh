#!/bin/bash

CRON="script02"

echo "00 04 * * 1 (sudo apt-get update -y && sudo apt-get upgrade -y) | sudo tee /var/log/update_script.log" >> /tmp/$CRON

crontab /tmp/$CRON
rm /tmp/$CRON
