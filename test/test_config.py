class Config(object):   
    # Labs settings
    labs_config = {
        'server_name': 'test_server',
        'duration': 15, # minutes
        'labs': [{
            'lab_name' : 'in4labs_perception',
            'html_name' : 'Perception Laboratory',
            'description' : 'This lab performs sensors experiments on Arduino devices',
            'host_port' : 8004,
            'cam_url': 'http://ULR_TO_WEBCAM/Mjpeg',
        }],
    }