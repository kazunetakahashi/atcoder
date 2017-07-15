n = gets.to_i
a = gets.chomp.split(" ")
sum = a.inject(:+)
now = 0
ans = sum
for i in 1..n-1
  now += a[i]
end
ans = [ans, (sum-now - now).abs].min
puts ans
