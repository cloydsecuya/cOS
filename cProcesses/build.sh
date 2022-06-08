echo -e "Initiating script to build C files"
echo -e "Make sure that this is outside of both your src directory with your out directory"
echo -e "Compiling now....."
echo "Current working directory:"
pwd


gcc -o out/processes src/processes.c
