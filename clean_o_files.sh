#!/bin/bash

# Check if the script is being executed directly or sourced
if [[ $0 != $BASH_SOURCE ]]; then
  echo "This script should be executed directly, not sourced."
  exit 1
fi

# Get the current directory
current_dir=$(pwd)

# Find all *.o files in the current directory and delete them
find "$current_dir" -type f -name "*.o" -delete

# Print a message indicating that the cleanup is complete
echo "Cleanup complete!"