# coding: utf-8
require 'FileUtils'

submitter_file = File.expand_path("auto-submitter/submitter.rb")

name = ARGV[0]
if name.nil? || name == ""
  puts "引数に名前は必須です。"
  exit
end

now = Time.now
year = now.strftime("%Y")
date = now.strftime("%m%d")
str = "#{year}/#{date}_#{name}"
make_dir = File.expand_path(str)

FileUtils.mkdir_p(make_dir)
puts "#{str} を作成しました。"
FileUtils.cp(submitter_file, make_dir)
`open #{make_dir}/submitter.rb`
