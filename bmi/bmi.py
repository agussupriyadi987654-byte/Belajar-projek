print("Kalkulator BMI")
print("==============")
berat = float(input("Masukan berat (dalam kg) : "))
tinggi = float(input("Masukan tinggi (dalam m) : "))
if berat == 0 or tinggi == 0:
    print("Nilai jangan nol")
else:
    bmi = berat/tinggi**2
    print(f"Score BMI kamu adalah {bmi:.2f}")
    if bmi < 18.5:
        status = "Underweight"
    elif bmi < 24.9:
        status = "Ideal"
    elif bmi < 29.9:
        status = "Overweight"
    else:
        status = "Obesitas"
    print(f"Kamu termasuk {status}")

