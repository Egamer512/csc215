* Mkae decides if it should run a specific target if that target doesn't exist or the preqreuisite is newer than the target itself. This is mportant beacuse if the pre-req was modified, then make should recompile the file. If the pre-req has not changed, then it should not be recomlpied!

Example: 
some_file: other_file
	echo "This will always run, and runs second"
	touch some_file

other_file:
	echo "This will always run, and runs first"

clean is often used as a target that removs the output of other targets, but it is not special word in Make. You can run make and thus make clean to create and delete a file.

Clean Example: 

some_file: 
	touch some_file

clean:
	rm -f some_file


