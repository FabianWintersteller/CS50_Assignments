from sys import argv, exit
import csv

# Check user input
if len(argv) != 3:
    print("INPUT FAIL")
    exit(1)

# File naming
database_path = argv[1]
seq_path = argv[2]

# File open
data_file = open(database_path, "r")
seq_file = open(seq_path, "r")

# Create database reader
data_reader = csv.DictReader(data_file)

# Read file into data structs
database = list(data_reader)
sequence = seq_file.read()

# Create variable for counting the max STR
max_counts = []

# Loop STR into datastructure
for i in range(1, len(data_reader.fieldnames)):
    STR = data_reader.fieldnames[i]
    max_counts.append(0)

    # Loop through sequence to find STR
    for j in range(len(sequence)):
        STR_count = 0

        # If match found start counting
        if sequence[j:(j + len(STR))] == STR:
            length = 0

            while sequence[(j + length): (j + length + len(STR))] == STR:
                STR_count += 1
                length += len(STR)

            if STR_count > max_counts[i - 1]:
                max_counts[i - 1] = STR_count

for i in range(len(database)):
    matches = 0

    for j in range(1, len(data_reader.fieldnames)):

        if int(database[i][data_reader.fieldnames[j]]) == int(max_counts[j - 1]):
            matches += 1

        if int(matches) == (int(len(data_reader.fieldnames)) - 1):
            print(database[i]['name'])
            exit(0)

print("No match")