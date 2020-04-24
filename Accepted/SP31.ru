n = gets.to_i
for i in 1..n
	x,y = gets.split.map(&:to_i)
	print x * y
	puts("\n")
end