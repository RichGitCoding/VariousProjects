import smtplib

sender = "[youremail]@gmail.com" #enter your email here
reciver= "[recivingemail]@gmail.com" #enter reciving email here
password= "[yourpassword]" #enter your password here
body = "Your message"
subject = "Subject of your message"


message = f"""From: Automation{sender}
To: {reciver}
Subject: {subject}\n
{body}
"""


server = smtplib.SMTP("smtp.gmail.com", 587)#587 is default email port
server.starttls()

try:
    server.login(sender,password)
    print("Logged in...")
    server.sendmail(sender, reciver,message)
    print("Email sent.")
except smtplib.SMTPAuthenticationError:
    print("Username or Password is incorrect.")

