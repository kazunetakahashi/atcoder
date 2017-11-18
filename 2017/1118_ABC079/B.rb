n = gets.chomp
l = Array.new(100)
l[0] = 2
l[1] = 1
for i in 2...100
  l[i] = l[i-1] + l[i-2]
end
puts l[n]
