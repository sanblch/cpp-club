FROM jupyter/minimal-notebook:612aa5710bf9

USER root

COPY notebooks notebooks

RUN chown -R $NB_UID notebooks

RUN apt-get update && apt-get install -yq --no-install-recommends \
  libeigen3-dev \
  && apt-get clean && rm -rf /var/lib/apt/lists/*

USER $NB_UID

RUN conda install cling \
  ipyleaflet \
  xeus-cling \
  xleaflet \
  xtensor \
  xproperty \
  xtensor-blas \
  xtensor-io \
  widgetsnbextension \
  -c conda-forge
RUN conda install xevo -c giorgosR


EXPOSE 8888

ENTRYPOINT ["jupyter", "notebook", "--port=8888", "--no-browser", "--ip=0.0.0.0", "--allow-root"]
