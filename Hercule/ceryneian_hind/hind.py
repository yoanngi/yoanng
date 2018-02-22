# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    hind.py                                          .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/02/21 10:59:11 by yoginet      #+#   ##    ##    #+#        #
#    Updated: 2018/02/21 16:45:09 by yoginet     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

#!/usr/bin/env python
# coding: utf-8

import requests
from oauth_hook import OAuthHook

from requests_oauthlib import OAuth1Session
from requests.auth import HTTPBasicAuth

client_key = ""
client_secret = ""
url = "https://api.intra.42.fr/v2/locations"
request_token_url = ""

client = requests.get(request_token_url, auth=(client_key, client_secret))
print client.content
print client.status_code
