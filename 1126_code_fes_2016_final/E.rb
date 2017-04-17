n, a = gets.chomp.split(" ").map{|x| x.to_i}

ans = n

for x in 1...32
  for k in 0..x
    l = x - k
    # puts "x = #{x}, k = #{k}"
    m = (n**(1.0/x)-1).ceil()
    if m**k * (m+1)**l >= n
      ans = [ans, m * k + (m+1) * l + a * (k + l - 1)].min()
    end
  end
end

puts ans

