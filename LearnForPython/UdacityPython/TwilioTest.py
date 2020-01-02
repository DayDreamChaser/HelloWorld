# Sending an SMS using the Twilio API
from twilio.rest import Client

# put your own credentials here
account_sid = "AC5ef872f6da5a21de157d80997a64bd33"
auth_token = "your_auth_token"
client = Client(account_sid, auth_token)

client.messages.create(
  to="+16518675309",
  from_="+14158141829",
  body="Tomorrow's forecast in Financial District, San Francisco is Clear",
  media_url="https://climacons.herokuapp.com/clear.png")