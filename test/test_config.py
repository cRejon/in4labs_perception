class Config(object):   
        # Labs settings
    labs_config = {
        'server_name': 'test_server',
        'mountings': [{
            'id': '2', 
            'duration': 10, # minutes
            'cam_url': 'https://ULR_TO_WEBCAM/stream.m3u8',
            'host_port' : 8002,
        },],
        'labs': [{
            'lab_name' : 'in4labs_perception',
            'html_name' : 'Perception Laboratory',
            'description' : 'In this Lab, experiments are carried out with sensors and actuators in Arduino.',
            'mounting_id': '2',
        }],
    }
