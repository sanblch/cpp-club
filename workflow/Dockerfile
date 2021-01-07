FROM ubuntu:20.04

ENV PATH="/root/miniconda3/bin:${PATH}"
ARG PATH="/root/miniconda3/bin:${PATH}"

RUN apt-get update

RUN apt-get install -y binutils git make unzip wget && rm -rf /var/lib/apt/lists/*

RUN wget \
  https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh \
  && mkdir /root/.conda \
  && bash Miniconda3-latest-Linux-x86_64.sh -b \
  && rm -f Miniconda3-latest-Linux-x86_64.sh

RUN conda --version

COPY ./environment-dev.yml ./cling.yml
ARG conda_env=xeus-cling
RUN conda env create -n ${conda_env} -f cling.yml
RUN echo "source activate $(head -1 ./cling.yml | cut -d' ' -f2)" >> ~/.bashrc
ENV PATH /root/miniconda3/envs/$conda_env/bin:$PATH
ENV LD_LIBRARY_PATH /root/miniconda3/envs/$conda_env/lib
ENV CONDA_DEFAULT_ENV $conda_env

RUN conda install gxx_linux-64 libcxx -c conda-forge
RUN wget \
  https://codeload.github.com/jupyter-xeus/xeus-cling/zip/0.10.0 -O xeus-cling-0.10.0.zip \
  && unzip xeus-cling-0.10.0.zip
RUN ls -F /root/miniconda3/envs/$conda_env/bin
RUN mkdir build \
  && cd build \
  && cmake ../xeus-cling-0.10.0 -DCMAKE_PREFIX_PATH=$CONDA_PREFIX -DCMAKE_INSTALL_PREFIX=$CONDA_PREFIX -DDOWNLOAD_GTEST=ON -DCMAKE_INSTALL_LIBDIR=lib -DCMAKE_C_COMPILER=/root/miniconda3/envs/$conda_env/bin/x86_64-conda-linux-gnu-gcc -DCMAKE_CXX_COMPILER=/root/miniconda3/envs/$conda_env/bin/x86_64-conda-linux-gnu-g++
RUN cd build \
  && make install -j16

# RUN conda install xeus-cling -c conda-forge
RUN conda install notebook -c conda-forge
RUN jupyter kernelspec install /share/jupyter/kernels/xcpp17 --sys-prefix

EXPOSE 8888

ENTRYPOINT ["jupyter", "notebook", "--port=8888", "--no-browser", "--ip=0.0.0.0", "--allow-root"]

# COPY ./environment-dev.yml ./cling.yml

# RUN wget \
#   https://codeload.github.com/jupyter-xeus/xeus-cling/zip/0.10.0 \
#   && unzip 0.10.0

# RUN conda config --set always_yes yes --set changeps1 no \
#   && conda update -q conda \
#   && conda env create -n xeus-cling --file cling.yml

# RUN source activate xeus-cling \
#   && conda install gxx_linux-64 libcxx -c conda-forge

# RUN source activate xeus-cling \
#   && mkdir build \
#   && cd build \
#   && cmake -DCMAKE_PREFIX_PATH=$CONDA_PREFIX -DCMAKE_INSTALL_PREFIX=$CONDA_PREFIX -DDOWNLOAD_GTEST=ON -DCMAKE_INSTALL_LIBDIR=lib -DCMAKE_C_COMPILER=$CC -DCMAKE_CXX_COMPILER=$CXX xeus-cling-0.10.0

# RUN source activate xeus-cling \
#   && make install -j16
