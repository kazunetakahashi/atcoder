k = gets.to_i

k /= k.gcd(10)

def sum(k)
  ans = 0
  k.to_s.chars{|i|
    ans += i.to_i
  }
  return ans
end

for i in 1...2000
  str = ""
  i.times{
    str += "1"    
  }
  if str.to_i % k == 0
    puts sum(k)
    exit
  end
end

if k%9 == 0
  puts 9
  exit
end

if k%3 == 0
  puts 3
  exit
end

puts 2


