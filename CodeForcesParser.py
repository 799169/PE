from urllib.request import urlopen
from html.parser import HTMLParser

url = """

https://codeforces.com/problemset/problem/1326/G


"""

num_cases = 0

with open("input2.txt", 'wb') as inputFile:
	with open("output2.txt", 'wb') as outputFile:

		class CodeforcesProblemParser(HTMLParser):

			def __init__(self):
				HTMLParser.__init__(self)
				self.num_tests = 0
				self.testcase = False
				self.start_copy = False
				self.useInputFile = False
				self.useOutputFile = False

			def handle_starttag(self, tag, attrs):
				global num_cases
				if tag == 'div':
					if attrs == [('class', 'input')]:
						self.num_tests += 1
						num_cases += 1
						self.testcase = True
						self.useInputFile = True
						self.useOutputFile = False
					elif attrs == [('class', 'output')]:
						self.testcase = True
						self.useInputFile = False
						self.useOutputFile = True
				elif tag == 'pre':
					if self.testcase:
						self.start_copy = True

			def handle_endtag(self, tag):
				if tag == 'br':
					if self.start_copy:
						if self.useInputFile: 
							inputFile.write('\n'.encode('utf-8'))
						else:
							outputFile.write('\n'.encode('utf-8'))
						self.end_line = True
				if tag == 'pre':
					if self.start_copy:
						if not self.end_line:
							if self.useInputFile: 
								inputFile.write('\n'.encode('utf-8'))
							else:
								outputFile.write('\n'.encode('utf-8'))
						self.testcase = False
						self.useInputFile = False
						self.useOutputFile = False
						self.start_copy = False

			def handle_entityref(self, name):
				if self.start_copy:
					inputFile.write(self.unescape(('&%s;' % name)).encode('utf-8'))

			def handle_data(self, data):
				if self.start_copy:
					if self.useInputFile: 
						inputFile.write(data.strip('\n').encode('utf-8'))
					else:
						outputFile.write(data.strip('\n').encode('utf-8'))
					self.end_line = False

		html = urlopen(url).read()
		parser = CodeforcesProblemParser()
		parser.feed(html.decode('utf-8'))


with open("input2.txt", 'r') as inputFile:
	with open("input.txt", "w") as inp:
		inp.write(str(num_cases) + "\n" + inputFile.read())

