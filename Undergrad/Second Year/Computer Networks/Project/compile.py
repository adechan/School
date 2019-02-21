import os
import sys
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('-c', '--client', action='store_true')
parser.add_argument('-s', '--server', action='store_true')

args = parser.parse_args()

client_cpps = "client/*.cpp client/connect4/*.cpp client/graphics/*.cpp"
server_cpps = "server/*.cpp"

compile_str = "g++ -O3 *.cpp net/*.cpp {} -o connect4_{}"

app = None
if args.client:
	app = 'client'
	compile_str = compile_str.format(client_cpps, '{}');

if args.server:
	app = 'server'
	compile_str = compile_str.format(server_cpps, '{}');
	
if not app:
	parser.print_help()
	sys.exit()

print('Compiling {}...'.format(app))
os.system(compile_str.format(app, app))