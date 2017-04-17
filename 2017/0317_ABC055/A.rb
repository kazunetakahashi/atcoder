n = gets.to_i
ans = 0

for i in 1..n
  ans += 800
  if i % 15 == 0
    ans -= 200
  end
end

puts ans
