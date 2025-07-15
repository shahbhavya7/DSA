import os

def delete_exe_files(root_dir):
    deleted_files = 0
    for foldername, subfolders, filenames in os.walk(root_dir):
        for filename in filenames:
            if filename.endswith(".exe"):
                file_path = os.path.join(foldername, filename)
                try:
                    os.remove(file_path)
                    print(f"Deleted: {file_path}")
                    deleted_files += 1
                except Exception as e:
                    print(f"Failed to delete {file_path}: {e}")
    if deleted_files == 0:
        print("No .exe files found.")
    else:
        print(f"\nTotal .exe files deleted: {deleted_files}")

if __name__ == "__main__":
    current_directory = os.getcwd()
    print(f"Scanning for .exe files in: {current_directory}\n")
    delete_exe_files(current_directory)
