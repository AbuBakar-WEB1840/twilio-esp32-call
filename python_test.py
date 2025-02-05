from twilio.rest import Client

# Twilio credentials (get these from your Twilio console)
ACCOUNT_SID = 'your-account-sid'
AUTH_TOKEN = 'your-account-token'
TWILIO_NUMBER = 'twilio-number'
YOUR_PHONE_NUMBER = 'your-phone-number'

# Initialize Twilio Client
client = Client(ACCOUNT_SID, AUTH_TOKEN)

# Make a phone call
call = client.calls.create(
    to=YOUR_PHONE_NUMBER,  # Replace with your phone number
    from_=TWILIO_NUMBER,   # Your Twilio number
    twiml='<Response><Say>Hello! This is a test call from Twilio.</Say></Response>'
)

print(f"Call initiated: {call.sid}")
