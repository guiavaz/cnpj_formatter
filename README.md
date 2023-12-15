How to Download and Install Breadcrumbscnpj_formatter?

Avaliable only for Linux.

Requirements:
- Ubuntu-based distro;
- GTK;
- GNU Compiler Collection.

Installation Guide:

1. Install GTK;
   $ sudo apt-get install libgtk-3-dev
2. Clone cnpj_formatter repository;
3. Compile the source code with the links it with the GTK+ 3.0 libraries:
````
$ gcc -o cnpj cnpj.c ```pkg-config --cflags --libs gtk+-3.0```
```

4. Run:
`$./cnpj`


Usage Guide:
1. Run:
`$ ./cnpj`
2. Paste CNPJ to the program;
3. Click in "Formatar e Copiar";
4. Congratulations! The CNPJ is now formatted and copied to your clipboard.
