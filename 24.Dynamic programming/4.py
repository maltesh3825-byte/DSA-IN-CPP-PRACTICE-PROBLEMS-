import pyautogui
import time
import random

pyautogui.FAILSAFE = True

# =============================
# SETTINGS
# =============================

SQUARE_SIZE = 100
TYPE_INTERVAL = 0.18      # Approximately 100 WPM
MIN_WAIT = 1
MAX_WAIT = 3
CLICK_INTERVAL = 10        # Click every 10 seconds

# =============================
# PYTHON CODE
# =============================

code_template = """def calculate_sum(numbers):
    total = 0
    for number in numbers:
        total += number
    return total

def calculate_average(numbers):
    if not numbers:
        return 0
    return calculate_sum(numbers) / len(numbers)

numbers = []
for i in range(100):
    numbers.append(i)

total = calculate_sum(numbers)
average = calculate_average(numbers)

print("Total:", total)
print("Average:", average)

class Student:
    def __init__(self, name, marks):
        self.name = name
        self.marks = marks

    def display(self):
        print("Name:", self.name)
        print("Marks:", self.marks)

students = []

for i in range(20):
    student = Student("Student" + str(i), i * 5)
    students.append(student)

for student in students:
    student.display()

for i in range(20):
    if i % 2 == 0:
        print("Even:", i)
    else:
        print("Odd:", i)

data = [10, 20, 30, 40, 50]

for value in data:
    print("Value:", value)

squared = []

for value in data:
    squared.append(value * value)

print("Squared:", squared)

numbers = list(range(50))

for number in numbers:
    if number % 5 == 0:
        print("Multiple of five:", number)

def find_max(values):
    maximum = values[0]

    for value in values:
        if value > maximum:
            maximum = value

    return maximum

def find_min(values):
    minimum = values[0]

    for value in values:
        if value < minimum:
            minimum = value

    return minimum

print("Maximum:", find_max(numbers))
print("Minimum:", find_min(numbers))

for i in range(10):
    print("Loop:", i)

message = "Python testing"

for character in message:
    print(character)

dictionary = {
    "name": "Test",
    "language": "Python",
    "version": 3
}

for key, value in dictionary.items():
    print(key, value)

values = []

for i in range(30):
    values.append(i)

print(values)

def greet(name):
    return "Hello " + name

names = [
    "Alex",
    "John",
    "Sam",
    "David",
    "Mike"
]

for name in names:
    print(greet(name))

counter = 0

while counter < 10:
    print("Counter:", counter)
    counter += 1

result = 1

for i in range(1, 11):
    result *= i

print("Factorial:", result)

items = ["apple", "banana", "orange", "grape"]

for item in items:
    print("Item:", item)

for i in range(10):
    for j in range(5):
        print(i, j)

def is_even(number):
    return number % 2 == 0

for i in range(25):
    print(i, is_even(i))

text = "Python is powerful"

words = text.split()

for word in words:
    print("Word:", word)

numbers = [1, 2, 3, 4, 5]

doubled = [number * 2 for number in numbers]

print(doubled)

tripled = [number * 3 for number in numbers]

print(tripled)

for i in range(20):
    print("Testing line:", i)

print("Program finished")
"""

python_code = code_template * 4

# =============================
# MOUSE SQUARE
# =============================

print("Move your mouse to the center of the area.")
print("You have 5 seconds...")

time.sleep(5)

start_x, start_y = pyautogui.position()

half = SQUARE_SIZE // 2

left = start_x - half
right = start_x + half
top = start_y - half
bottom = start_y + half

print("Mouse square created.")
print("Clicking every 10 seconds.")
print("Press Ctrl+C to stop.")

# Start click timer
last_click = time.time()

# =============================
# MAIN LOOP
# =============================

try:

    while True:

        for line in python_code.splitlines():

            # Type line
            pyautogui.write(
                line,
                interval=TYPE_INTERVAL
            )

            pyautogui.press("enter")

            # -------------------------
            # MOUSE MOVEMENT
            # -------------------------
# MOUSE MOVEMENT + CLICK
# -------------------------

            x = random.randint(left, right)
            y = random.randint(top, bottom)

            pyautogui.moveTo(
                x,
                y,
                duration=random.uniform(0.2, 0.6)
            )

            # Click immediately after every movement
            pyautogui.click()

          
            time.sleep(
                random.uniform(MIN_WAIT, MAX_WAIT)
            )

except KeyboardInterrupt:

    print("\nStopped with Ctrl+C.")

print("Test finished.")
