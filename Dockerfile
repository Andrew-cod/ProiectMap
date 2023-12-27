# Use a base image with a minimal environment
FROM gcc:latest

# Set the working directory inside the container
WORKDIR /app

# Copy the local code into the container at /app
COPY . /app

# Compile the C code
RUN gcc -o myapp calul.c

# Specify the command to run on container startup
CMD ["./myapp"]
