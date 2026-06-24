--[[

Level4

 1
 23
 456
 78910

 Level 5

    *
   ***
  *****
 *******

]]

local a = 4
local b = 1
for i=0,a-1 do
	for j=0,i do
		io.write(b)
		b=b+1
	end
	print()	
end
print()
for i=0,a*2-1,2 do
	for j=0,a-i/2+1 do
		io.write(" ")
	end
	for j=0,i do
		io.write("*")
	end
	print()
end
