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

client_key = "f5b1dffa388699fbc01c0a3d0f5da676768392bf9690b78563947a1e1ad29410"
client_secret = "64d524acd61b89bb1f30151dba6e9434e1b3692e71f4541e7e679363e6e1fba1"
url = "https://api.intra.42.fr/v2/locations"
request_token_url = "https://api.intra.42.fr/oauth/authorize?client_id=f5b1dffa388699fbc01c0a3d0f5da676768392bf9690b78563947a1e1ad29410&redirect_uri=https%3A%2F%2Fprofile.intra.42.fr%2F&response_type=code"

client = requests.get(request_token_url, auth=(client_key, client_secret))
print client.content
print client.status_code
