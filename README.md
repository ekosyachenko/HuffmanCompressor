# HuffmanCompressor
File compressor/decompressor program using Huffman encoding algorithm. Written in C++ 

<b>Purpose</b>

This program will illustrate the usage of Huffman encoding, heaps, and priority queues. It will
also require a good factoring design.

<b>Part I: Compress</b>

Create a program called Compress which takes as an argument a file, filename. The program
will create a file, filename.huf, which contains a compressed version of the file. The program
should use the Huffman encoding to compress the file. You will do the encoding at the
character level.

<b>Part II: Expand</b>

Create a program called Expand which takes as an argument a file which has been encoded by
your part I, filename.huf. This program will create a file, filename.huf.puf, which decodes and
uncompresses the file.

If you run these commands:

 * <i>Compress myFile</i>
 * <i>Uncompress myFile.huf</i>

Then myFile and and myFile.huf.puf should be identical.
