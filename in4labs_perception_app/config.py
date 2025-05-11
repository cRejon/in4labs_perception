import os


class Config(object):
    # Boards configuration
    boards_config = {
        'Board_1':{
            'name':'Mega 2560',
            'model':'Arduino Mega 2560 Rev3',
            'fqbn':'arduino:avr:mega',
            'usb_port':'3',
        }
    }

    # Docker environment variables
    server_name = os.environ.get('SERVER_NAME')
    lab_name = os.environ.get('LAB_NAME')
    user_email = os.environ.get('USER_EMAIL') 
    end_time = os.environ.get('END_TIME') 
    cam_url = os.environ.get('CAM_URL') 

    # Flask environment variable needed for session management
    flask_config = {
        # Use as secret key the user email + the end time of the session 
        'SECRET_KEY': user_email + end_time,
    }
