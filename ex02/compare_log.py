def read_log(file_path):
    with open(file_path, 'r') as file:
        return file.readlines()

def strip_date(log_line):
    return log_line[20:].strip()

def compare_logs(log1, log2):
    discrepancies = []
    for i, (line1, line2) in enumerate(zip(log1, log2)):
        if strip_date(line1) != strip_date(line2):
            discrepancies.append((i, line1.strip(), line2.strip()))
    return discrepancies

def print_discrepancies(discrepancies):
    if not discrepancies:
        print("No discrepancies found.")
    else:
        print(f"Found {len(discrepancies)} discrepancies:")
        for i, line1, line2 in discrepancies:
            print(f"Line {i + 1}:")
            print(f"  Log1: {line1}")
            print(f"  Log2: {line2}")

def main():
    log1_path = '19920104_091532.log'
    log2_path = 'account.log'

    log1 = read_log(log1_path)
    log2 = read_log(log2_path)

    discrepancies = compare_logs(log1, log2)
    print_discrepancies(discrepancies)

if __name__ == "__main__":
    main()
