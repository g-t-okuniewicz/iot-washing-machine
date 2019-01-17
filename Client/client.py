#Base Python client for MEng in IoT Assignment
#consumes data from IoT Gateway
import urllib3
import xml.etree.cElementTree as et
import re

import dash
import dash_core_components as dcc
import dash_html_components as html

http = urllib3.PoolManager()

url  = 'http://localhost:8080/'

response = http.request('GET', url)

xml_string = '<sensor_readings>'
xml_string += response.data.decode('ascii')
xml_string += '</sensor_readings>'

water_temp_timestamps = []
water_temps = []

water_level_timestamps = []
water_levels = []

sensor_readings = et.fromstring(xml_string)

for reading in sensor_readings:
    if(reading.find('measurement').text == 'water_level'):
        water_level_timestamps.append(reading.find('timestamp').text)
        water_levels.append(float(reading.find('value').text))
    if(reading.find('measurement').text == 'water_temp'):
        water_temp_timestamps.append(reading.find('timestamp').text)
        water_temps.append(float(reading.find('value').text))

#------------------------
external_stylesheets = ['https://codepen.io/chriddyp/pen/bWLwgP.css']

app = dash.Dash(__name__, external_stylesheets=external_stylesheets)

app.layout = html.Div(children=[
    html.H1(children='IoT Washing Machine'),

    html.Div(children='''
        Dash: A web application framework for Python.
    '''),

    dcc.Graph(
        id='temp-graph',
        figure={
            'data': [
                {'x': water_level_timestamps, 'y': water_levels, 'type': 'scatter', 'name': 'Water Level (l)'},
                {'x': water_temp_timestamps, 'y': water_temps, 'type': 'bar', 'name': 'Water Temperature (°C)'},
            ],
            'layout': {
                'title': 'Water Temperature and Water Level'
            }
        }
    )
])

if __name__ == '__main__':
    app.run_server(debug=True)