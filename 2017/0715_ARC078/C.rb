n = gets.to_i
a = gets.chomp.split(" ").map{|i| i.to_i}
sum = a.inject(:+)
now = a[0]
ans = (sum-now-now).abs
for i in 1...(n-1)
  puts i
  now += a[i]
  ans = [ans, (sum-now - now).abs].min
end
puts ans
