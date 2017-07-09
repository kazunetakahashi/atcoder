def choose(n, k)
  if k == 0
    return 1
  else
    return choose(n, k-1) * (n - k + 1)/ k
  end
end

n, p = gets.chomp.split(" ").map{|i| i.to_i}
a = gets.chomp.split(" ").map{|i| i.to_i}

odd = 0
even = 0

a.each{|it|
  if it % 2 == 0
    even += 1
  else
    odd += 1
  end
}

ans = 0

for i in 0...odd
  if (i%2 == p)
    ans += (2 ** even) * choose(odd, i)
  end
end

puts ans

