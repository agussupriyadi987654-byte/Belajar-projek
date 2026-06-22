print("Kalkulator BMI")
print("==============")
io.write("Masukan berat badan (dalam kg) :")
local berat = tonumber(io.read())
io.write("Masukan tinggi badan (dalam m) :")
local tinggi = tonumber(io.read())
if berat == 0 or tinggi == 0 then
	print("Nilai tidak boleh nol")
else
	local bmi = berat/tinggi^2
	print("Score bmi anda "..string.format("%.2f", bmi))
	local status
	if bmi<18.5 then
		status = "underweight"
	elseif bmi<24.9 then
		status = "ideal"
	elseif bmi<29.9 then
		status = "overweight"
	else
		status = "obesitas"
	end
	print("kamu termasuk "..status)
end
