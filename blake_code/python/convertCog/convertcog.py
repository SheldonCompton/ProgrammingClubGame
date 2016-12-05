#!/usr/bin/python

import xlsxwriter
import re

filelist = ['unformatted/a.txt', 'unformatted/b.txt', 'unformatted/c.txt', 'unformatted/d.txt', 'unformatted/e.txt', 'unformatted/f.txt', 'unformatted/g.txt', 'unformatted/h.txt', 'unformatted/i.txt', 'unformatted/j.txt', 'unformatted/k.txt', 'unformatted/l.txt', 'unformatted/m.txt', 'unformatted/n.txt', 'unformatted/o.txt', 'unformatted/p.txt', 'unformatted/q.txt', 'unformatted/r.txt', 'unformatted/s.txt', 'unformatted/t.txt', 'unformatted/u.txt', 'unformatted/v.txt', 'unformatted/w.txt', 'unformatted/x.txt', 'unformatted/y.txt', 'unformatted/z.txt']
row = 0

workbook = xlsxwriter.Workbook('cognitarium.xlsx')
worksheet = workbook.add_worksheet()

for filename in filelist:
    with open(filename, 'r') as dicfile:
        for line in dicfile:
            name = re.search('name="(.+?)"', line)
            if name:
                namestring = name.group(1)
                worksheet.write(row, 0, namestring)

            define = re.search('"define">{(.+?)}', line)
            if define:
                definestring = define.group(1)
                worksheet.write(row, 1, definestring)
            
            print(namestring + "\t:  " + definestring)
            row = row + 1
    dicfile.close()
workbook.close()
