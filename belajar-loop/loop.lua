--[[
 tantangan :
 step harus positif

 Target :
 Level1

 ****
 ***
 **
 *       

 Level2
 1
 22
 333
 4444

 level3
 1
 12
 123
 1234
 ]]

local a = 3
for i=0,a do
	for j=0,a-i do
		io.write("*")
	end
	print()
end
print()
for i=0,a do
        for j=0,i do
                io.write(i+1)
        end
        print()
end

print()
for i=0,a do
        for j=0,i do
                io.write(j+1)
        end
        print()
end
