n, k = gets.chomp.split(" ").map{|i| i.to_i}
a = gets.chomp.split(" ").map{|i| i.to_i}

a.sort!.reverse!
sum = a.inject(:+)

if sum < k
  puts "-1"
else
  t = 0
  cnt = 0
  while t < k
    t += a[cnt]
    cnt += 1
  end
  puts cnt
end
