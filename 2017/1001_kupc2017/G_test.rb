`g++-5 -std=gnu++1y -O2 -I/opt/local/boost/include -L/opt/local/boost/lib -Wall G.cpp`
random = Random.new
while true
  i = random.rand(0...1e18).to_i
  puts "i = #{i}"
  open("Gmoto.txt") {|input|
    open("Gin1.txt", 'w') {|output|
      input.each_line {|line|
        output.puts(line)
      }
      output.puts(i.to_s)
    }
  }
  `./a.out < Gin1.txt > Gout1.txt`
  open("Gout1.txt") {|input|
    open("Gin2.txt", 'w') {|output|
      output.puts("decode")
      output.puts("100")
      input.each_line {|line|
        output.puts(line)
      }
    }
  }
  `./a.out < Gin2.txt > Gout2.txt`
  ok = true
  open("Gout2.txt") {|input|
    j = input.read.chomp.to_i
    if i == j
      puts "passed #{i}"
    else
      puts "failed i = #{i}, j = #{j}"
      ok = false
    end
  }
  if !ok
    exit
  end
end
