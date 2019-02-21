import subprocess
import argparse
import sys

class bcolors:
	blue = '\033[94m'
	green = '\033[92m'
	red = '\033[91m'
	white = '\033[0m'
	
def color_red(text):
	return bcolors.red + text;

def color_blue(text):
	return bcolors.blue + text;
	
def color_white(text):
	return bcolors.white + text;
	
def color_green(text):
	return bcolors.green + text;

def clean():
	print(color_blue('[*] ') + color_white('Cleaning yacc output files...'));
	print(color_red(''));
	subprocess.check_output('rm y.output; rm y.tab.c; rm y.tab.h', shell = True);
	
	print(color_blue('[*] ') + color_white('Cleaning lex output files...'));
	print(color_red(''));
	subprocess.check_output('rm lex.yy.c', shell = True);
	
	print(color_green('[+] ') + color_white('Done'));
	
def compile():
	print(color_blue('[*] ') + color_white('Compiling parser...'));
	print(color_red(''));
	subprocess.check_output('yacc -dvt --locations parser.y', shell = True);

	print(color_blue('[*] ') + color_white('Compiling lexer...'));
	print(color_red(''));
	subprocess.check_output('lex lexer.l', shell = True);

	print(color_blue('[*] ') + color_white('Compiling main program...'));
	print(color_red(''));
	subprocess.check_output('g++ main.cpp lexer/*.cpp parser/*.cpp y.tab.c lex.yy.c -o main', shell = True);

	print(color_green('[+] ') + color_white('Compiled into program: main'));

parser = argparse.ArgumentParser()
parser.add_argument("-c", "--compile", action='store_true')
parser.add_argument("-l", "--clean", action='store_true')

args = parser.parse_args()

if not args.clean:
	compile();
else:
	clean();