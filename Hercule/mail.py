#!/usr/bin/env python
#-*- coding: utf-8 -*-

import yagmail
import sys

if (len(sys.argv) != 5):
	print ("usage : ./mail.py [email target] [subject]  \"my message\" [PASSWORD]")
	print ("Setting : mail.poupabelle.69@gmail.com, please change code for change email")
else:
	FROM = 'mail.poupabelle.69@gmail.com'
	TO = sys.argv[1]
	SUBJECT = sys.argv[2]
	TEXT = sys.argv[3]
	PASS = sys.argv[4]
	yag = yagmail.SMTP('mail.poupabelle.69@gmail.com', PASS , host='smtp.gmail.com', port=587, smtp_starttls=True, smtp_ssl=False)
	yag.send(TO, SUBJECT, TEXT)
	print ("Success")
	sys.exit(1)

