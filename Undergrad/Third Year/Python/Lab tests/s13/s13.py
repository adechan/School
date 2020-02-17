
import os;
import zipfile
import sqlite3

def is_file(path):
    if os.path.isfile(path):
        return True
    return False

#def problema1(path, low, high):

#	list_tracks = []
#	list_genres = []
#	list_albums = []

#	for root, dirs, files in os.walk(path):
#		for file in files:
#			if file.endswith(".zip"):
				
#				join_path = os.path.join(path, file)
#				with zipfile.ZipFile(join_path, "r") as zip_ref:
					
					#if "sample.sqlite" in zip_ref.filename():

						#zip_ref.extractall("Directory")

						#conn = sqlite3.connect('sample.sqlite')
						#c = conn.cursor()
						#c.execute("SELECT * FROM tracks")
						#track = c.fetchall()
						#list_track.append(track)

						#c.execute("SELECT * from genres")
						#genre = c.fetchall()
						#list_genres = c.fetchall()

						#c.execute("SELECT * from albums")
						#album = c.fetchall()
						#list_albums = c.fetchall()

	#return list


def problema1(path, low, high):
	for root, dirs, files in os.walk(path):

		for file in files:
			if file.endswith(".zip"):

				join_path = os.path.join(path, file)
				join_replace = join_path.replace("\\", "/")
				print(join_replace)

				
				with zipfile.ZipFile(join_replace, "r") as zip_ref:
					#if "sample.sqlite" in zip_ref.filename():
						zip_ref.extractall("dir")

print(problema1("C:/Users/Andreea Rindasu/source/repos/s13", 130, 130))


