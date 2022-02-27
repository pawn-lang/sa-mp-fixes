<?xml version="1.0" ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
<!-- Version: $Id: pawndoc.xsl 3612 2006-07-22 09:59:46Z thiadmer $ -->

<xsl:template match="/">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<title><xsl:value-of select="doc/assembly/name" /></title>
<style type="text/css">
	body { font-family: "verdana", sans-serif; font-size: x-small; }
	code { font-size: small; }
	dl { margin-left: 4em; display: compact; }
	dt { font-weight: bold; }
	a:link { color: #4e4887; }
	a:visited { color: #8080c8; }
	a:active { color: #f16043; }
	a:hover { color: #f16043; }
	p { margin-bottom: 0.5em; margin-top: 0.5em; margin-left: 4em; }
	p.noindent { margin-left: 0em; }
	p.syntax { font-weight: bold; }
	hr.para { height: 0; border: 0; color: transparent; background-color: transparent; margin-top: 0.5em; margin-bottom: 0; }
	xmp { background-color: #ddeeff; font-size: x-small; margin: 1em; }
	pre { background-color: #ddeeff; font-size: x-small; margin: 1em; }
	table { border-bottom: medium none; border-left: medium none; border-right: medium none; border-top: medium none; }
	table.param { background-color: #ddeeff; }
	table.transition { background-color: #ddeeff; }
	td { background-color: #ddeeff; border-bottom: medium none; border-left: medium none; border-right: medium none; border-top: medium none; font-size: x-small; margin: 2px; padding-bottom: 2px; padding-left: 2px; padding-right: 2px; padding-top: 2px; text-align: left; }
	td.header { background-color: transparent; font-weight: bold; color: #4e4887; width: 3.3em; padding-left: 0px; margin-bottom: 0.5em; }
	td.inline { background-color: transparent; }
	td.param { font-weight: bold; font-style: italic; padding-right: 20px; }
	td.transition { padding-right: 10px; }
	th { background-color: #336699; color: #ddeeff; border-bottom: medium none; border-left: medium none; border-right: medium none; border-top: medium none; font-size: x-small; margin: 2px; padding-bottom: 2px; padding-left: 4px; padding-right: 4px; padding-top: 2px; text-align: left; }
	ul { margin-top: 0.5em; }
	li.referrer { display: inline; padding-right: 8px; }
	li.dependency { display: inline; padding-right: 8px; }
	li.seealso { display: inline; padding-right: 8px; }
	li.attribute { display: inline; padding-right: 8px; }
	li.post { display: inline; padding-right: 8px; }
	li.author { display: inline; padding-right: 8px; }
	li.fixes { display: inline; padding-right: 8px; }
	li.see { display: inline; padding-right: 8px; }
	li.changelog { display: inline; }
	.symbol { padding-right: 8px; }
	ol { margin-top: 0.5em; }
	span.paraminfo { font-weight:bold; color: #336699; }
	h1 { color: #4e4887; font-size: x-large; margin-bottom: 0.5em; margin-top: 1em; padding-left: 4px; }
	h2 { border-right: #4e4887 8px solid; border-top: #4e4887 2px solid; color: #4e4887; margin-bottom: 0.5em; margin-top: 1em; }
	h2.general { border: none; }
	h3 { color: #4e4887; font-size: x-small; margin-bottom: 0.5em; }
	h4 { color: #4e4887; font-size: x-small; font-style: italic; margin-bottom: 0.5em; display: inline; margin: 50px 8px 0px 0px; }
	h5 { color: #4e4887; font-size: xx-small; margin-bottom: 0.5em; }
	h6 { color: #4e4887; font-size: xx-small; font-style: italic; margin-bottom: 0.5em; }
	div.library { text-align: center; border-right: #4e4887 8px solid; border-top: #4e4887 2px solid; color: #4e4887; margin-bottom: 0.5em; margin-top: 1em; }
	h1.library { text-align: center; color: #4e4887; margin-top: 0.3em; }
	h2.library { text-align: center; border: none; }
	pre { background-color: #ddeeff; font-size: small; margin: 1em; }
	div.member-header { display: none; }
	div.members > .member-header:nth-child(1) { display: block; }
</style>
</head>
<body>
	<!-- <h1><xsl:value-of select="/doc/assembly/name" /></h1> -->
	<xsl:apply-templates select="/doc/general" />
	<xsl:apply-templates select="/doc/members/member" />
</body>
</html>
</xsl:template>

<xsl:template match="general">
    <xsl:apply-templates />
    <br />
</xsl:template>

<xsl:template match="member">
	<xsl:choose>
		<xsl:when test="substring(@name,1,2) = 'T:'">
			<a><xsl:attribute name="name"><xsl:value-of select="substring(@name,3)" /></xsl:attribute><h2><span style="float:right; padding-right:2px">enumeration</span><xsl:value-of select="substring(@name,3)" /></h2></a>
			<xsl:apply-templates select="summary" />
			<xsl:if test="remarks">
				<h3>Remarks</h3>
				<xsl:apply-templates select="remarks" />
			</xsl:if>
			<xsl:if test="member">
				<h3>Members</h3>
				<blockquote>
				<xsl:apply-templates select="member" />
				</blockquote>
			</xsl:if>
			<xsl:apply-templates select="example" />
			<xsl:if test="referrer">
				<h3>Used by</h3>
				<ul><xsl:apply-templates select="referrer" /></ul>
			</xsl:if>
			<xsl:if test="fixes">
				<h3>Fixes</h3>
				<ul><xsl:apply-templates select="fixes" /></ul>
			</xsl:if>
			<xsl:if test="dependency">
				<h3>Depends on</h3>
				<ul><xsl:apply-templates select="dependency" /></ul>
			</xsl:if>
			<xsl:if test="seealso">
				<h3>See Also</h3>
				<ul><xsl:apply-templates select="seealso" /></ul>
			</xsl:if>
		</xsl:when>
		<xsl:when test="substring(@name,1,2) = 'C:'">
			<a><xsl:attribute name="name"><xsl:value-of select="substring(@name,3)" /></xsl:attribute><h2><span style="float:right; padding-right:2px">constant</span><xsl:value-of select="substring(@name,3)" /></h2></a>
			<p class="noindent"><table><tr><td class="header inline">Value</td><td class="inline"><xsl:value-of select="@value" /></td></tr></table></p>
			<xsl:apply-templates select="summary" />
			<xsl:apply-templates select="tagname" />
			<xsl:apply-templates select="size" />
			<xsl:if test="remarks">
				<h3>Remarks</h3>
				<xsl:apply-templates select="remarks" />
			</xsl:if>
			<xsl:apply-templates select="example" />
			<xsl:if test="referrer">
				<h3>Used by</h3>
				<ul><xsl:apply-templates select="referrer" /></ul>
			</xsl:if>
			<xsl:if test="fixes">
				<h3>Fixes</h3>
				<ul><xsl:apply-templates select="fixes" /></ul>
			</xsl:if>
			<xsl:if test="dependency">
				<h3>Depends on</h3>
				<ul><xsl:apply-templates select="dependency" /></ul>
			</xsl:if>
			<xsl:if test="seealso">
				<h3>See Also</h3>
				<ul><xsl:apply-templates select="seealso" /></ul>
			</xsl:if>
		</xsl:when>
		<xsl:when test="substring(@name,1,2) = 'M:'">
			<a><xsl:attribute name="name"><xsl:value-of select="substring(@name,3)" /></xsl:attribute><h2><span style="float:right; padding-right:2px">function</span><xsl:value-of select="substring(@name,3)" /></h2></a>
			<xsl:apply-templates select="summary" />
			<h3>Syntax</h3><p class="syntax"><xsl:value-of select="@syntax" /></p>
			<xsl:if test="param">
				<p><table class="param"><xsl:apply-templates select="param" /></table></p>
			</xsl:if>
			<xsl:apply-templates select="tagname" />
			<xsl:apply-templates select="returns" />
			<xsl:if test="remarks">
				<h3>Remarks</h3>
				<xsl:apply-templates select="remarks" />
			</xsl:if>
			<xsl:apply-templates select="example" />
			<xsl:if test="referrer">
				<h3>Used by</h3>
				<ul><xsl:apply-templates select="referrer" /></ul>
			</xsl:if>
			<xsl:if test="fixes">
				<h3>Fixes</h3>
				<ul><xsl:apply-templates select="fixes" /></ul>
			</xsl:if>
			<xsl:if test="dependency">
				<h3>Depends on</h3>
				<ul><xsl:apply-templates select="dependency" /></ul>
			</xsl:if>
			<xsl:if test="attribute">
				<h3>Attributes</h3>
				<ul><xsl:apply-templates select="attribute" /></ul>
			</xsl:if>
			<xsl:apply-templates select="automaton" />
			<xsl:if test="transition">
				<h3>Transition table</h3>
				<p>
					<table class="transition">
						<tr><th>Source</th><th>Target</th><th>Condition</th></tr>
						<xsl:apply-templates select="transition" />
					</table>
				</p>
			</xsl:if>
			<xsl:apply-templates select="stacksize" />
			<xsl:if test="seealso">
				<h3>See Also</h3>
				<ul><xsl:apply-templates select="seealso" /></ul>
			</xsl:if>
		</xsl:when>
		<xsl:when test="substring(@name,1,2) = 'F:'">
			<a><xsl:attribute name="name"><xsl:value-of select="substring(@name,3)" /></xsl:attribute><h2><span style="float:right; padding-right:2px">variable</span><xsl:value-of select="substring(@name,3)" /></h2></a>
			<xsl:apply-templates select="summary" />
			<xsl:apply-templates select="tagname" />
			<xsl:if test="remarks">
				<h3>Remarks</h3>
				<xsl:apply-templates select="remarks" />
			</xsl:if>
			<xsl:apply-templates select="example" />
			<xsl:if test="referrer">
				<h3>Used by</h3>
				<ul><xsl:apply-templates select="referrer" /></ul>
			</xsl:if>
			<xsl:if test="fixes">
				<h3>Fixes</h3>
				<ul><xsl:apply-templates select="fixes" /></ul>
			</xsl:if>
			<xsl:if test="dependency">
				<h3>Depends on</h3>
				<ul><xsl:apply-templates select="dependency" /></ul>
			</xsl:if>
			<xsl:if test="seealso">
				<h3>See Also</h3>
				<ul><xsl:apply-templates select="seealso" /></ul>
			</xsl:if>
		</xsl:when>
	</xsl:choose>
</xsl:template>

<xsl:template match="summary">
	<p><xsl:apply-templates /></p>
</xsl:template>

<xsl:template match="param">
	<tr>
		<td class="param"><xsl:value-of select="@name" /></td>
		<td><xsl:apply-templates /></td>
	</tr>
</xsl:template>

<xsl:template match="paraminfo">
	<span class="paraminfo">&lt;<xsl:apply-templates />&gt;</span>
</xsl:template>

<xsl:template match="tagname">
	<p class="noindent"><table><tr>
		<td class="header inline">Tag</td>
		<td class="inline"><xsl:value-of select="@value" /></td>
	</tr></table></p>
</xsl:template>

<xsl:template match="size">
	<p class="noindent"><table><tr>
		<td class="header inline">Size</td>
		<td class="inline"><xsl:value-of select="@value" /></td>
	</tr></table></p>
</xsl:template>

<xsl:template match="returns">
	<h3>Returns</h3>
	<p><xsl:apply-templates /></p>
</xsl:template>

<xsl:template match="remarks">
	<p><xsl:apply-templates /></p>
</xsl:template>

<xsl:template match="example">
	<h3>Example</h3>
	<p><xsl:apply-templates /></p>
</xsl:template>

<xsl:template match="attribute">
	<li class="attribute"><xsl:value-of select="@name" /></li>
</xsl:template>

<xsl:template match="referrer">
	<li class="referrer"><a><xsl:attribute name="href">#<xsl:value-of select="@name" /></xsl:attribute><code><xsl:value-of select="@name" /></code></a></li>
</xsl:template>

<xsl:template match="dependency">
	<li class="dependency"><a><xsl:attribute name="href">#<xsl:value-of select="@name" /></xsl:attribute><code><xsl:value-of select="@name" /></code></a></li>
</xsl:template>

<xsl:template match="stacksize">
	<h3>Estimated stack usage</h3>
	<p><xsl:value-of select="@value" /> cells</p>
</xsl:template>

<xsl:template match="automaton">
	<h3>Automaton</h3>
	<p><xsl:value-of select="@name" /></p>
</xsl:template>

<xsl:template match="transition">
	<tr>
		<td class="transition"><xsl:value-of select="@source" /></td>
		<td class="transition"><xsl:value-of select="@target" /></td>
		<td><xsl:value-of select="@condition" /></td>
	</tr>
</xsl:template>

<xsl:template match="code">
	<pre><xsl:apply-templates /></pre>
</xsl:template>

<xsl:template match="seealso">
	<a><xsl:attribute name="href">#<xsl:value-of select="@name" /></xsl:attribute><code><xsl:value-of select="@name" /></code></a>
</xsl:template>

<xsl:template match="paramref">
	<i><xsl:value-of select="@name" /></i>
</xsl:template>

<xsl:template match="c"><code><xsl:apply-templates /></code></xsl:template>

<xsl:template match="em"><em><xsl:apply-templates /></em></xsl:template>

<xsl:template match="ul"><ul><xsl:apply-templates /></ul></xsl:template>

<xsl:template match="ol"><ol><xsl:apply-templates /></ol></xsl:template>

<xsl:template match="li"><li><xsl:apply-templates /></li></xsl:template>

<xsl:template match="p"><hr class="para" /><xsl:apply-templates /></xsl:template>

<xsl:template match="para"><hr class="para" /><xsl:apply-templates /></xsl:template>

<xsl:template match="section"><h1 class="general"><xsl:apply-templates /></h1></xsl:template>

<xsl:template match="subsection"><h2 class="general"><xsl:apply-templates /></h2></xsl:template>

<xsl:template match="library">
	<div class="library">
		<span style="float:right; padding-right:2px; height: 6em"><h1 class="library">library</h1></span>
		<h1 class="library">
			<xsl:value-of select="@name" />
		</h1>
		<xsl:if test="@description">
			<h2 class="library"><xsl:value-of select="@description" /></h2>
		</xsl:if>
	</div>
	<xsl:apply-templates />
	<div class="members">
		<xsl:if test="@name = 'fixes.inc'">
			<h1>Fixes</h1>
			<xsl:apply-templates select="/doc/members/member" mode="fixes" />
		</xsl:if>

		<xsl:apply-templates select="/doc/members/member" mode="library">
			<xsl:with-param name="library" select="@name" />
			<xsl:with-param name="type" select="'T:'" />
			<xsl:with-param name="title" select="'Enums'" />
		</xsl:apply-templates>

		<xsl:apply-templates select="/doc/members/member" mode="library">
			<xsl:with-param name="library" select="@name" />
			<xsl:with-param name="type" select="'C:'" />
			<xsl:with-param name="title" select="'Constants'" />
		</xsl:apply-templates>

		<xsl:apply-templates select="/doc/members/member" mode="library">
			<xsl:with-param name="library" select="@name" />
			<xsl:with-param name="type" select="'F:'" />
			<xsl:with-param name="title" select="'Variables'" />
		</xsl:apply-templates>

		<xsl:apply-templates select="/doc/members/member" mode="library">
			<xsl:with-param name="library" select="@name" />
			<xsl:with-param name="type" select="'M:'" />
			<xsl:with-param name="title" select="'Functions'" />
		</xsl:apply-templates>
	</div>
</xsl:template>

<xsl:template match="br"><br /></xsl:template>
<xsl:template match="indent">&#160;&#160;&#160;&#160;</xsl:template>

<xsl:template match="a">
	<xsl:choose>
		<xsl:when test="node()"><a><xsl:attribute name="href"><xsl:value-of select="@href" /></xsl:attribute><xsl:apply-templates /></a></xsl:when>
		<xsl:otherwise><a><xsl:attribute name="href"><xsl:value-of select="@href" /></xsl:attribute><xsl:value-of select="@href" /></a></xsl:otherwise>
	</xsl:choose>
</xsl:template>

<xsl:template match="symbolref">
	<a><xsl:attribute name="href">#<xsl:value-of select="@name" /></xsl:attribute><code><xsl:value-of select="@name" /></code></a>
</xsl:template>

<xsl:template match="symbol">
	<li><span class="symbol"><a><xsl:attribute name="href">#<xsl:value-of select="@name" /></xsl:attribute><code><xsl:value-of select="@name" /></code></a>:</span><xsl:apply-templates /></li>
</xsl:template>

<xsl:template match="synonym">
	<li><span class="symbol"><code><xsl:value-of select="@name" /></code>:</span>Synonym for <a><xsl:attribute name="href">#<xsl:value-of select="@for" /></xsl:attribute><code><xsl:value-of select="@for" /></code></a><xsl:apply-templates />.</li>
</xsl:template>

<xsl:template match="changelog">
	<li class="changelog"><h3 class="general"><xsl:value-of select="@date" /></h3>
	<ul><xsl:apply-templates /></ul></li>
</xsl:template>


<!-- fixes.inc -->

<xsl:template match="fix">
	<a><xsl:attribute name="name">FIX_<xsl:value-of select="@name" /></xsl:attribute><h2><span style="float:right; padding-right:2px">fix</span><xsl:value-of select="@name" /></h2></a>
	<xsl:if test="@fixed">
		<p><b>Fixed in <xsl:value-of select="@fixed" /></b></p>
	</xsl:if>
	<xsl:if test="@disabled">
		<xsl:if test="@disabled='true'">
			<p><b>Disabled By Default</b></p>
		</xsl:if>
	</xsl:if>

	<h3>Problem</h3>
	<xsl:apply-templates select="problem" />
	<h3>Solution</h3>
	<xsl:apply-templates select="solution" />
	<xsl:if test="see">
		<h3>See</h3>
		<ul><xsl:apply-templates select="see" /></ul>
	</xsl:if>
	<xsl:if test="author">
		<h3>Author(s)</h3>
		<ul><xsl:apply-templates select="author" /></ul>
	</xsl:if>
	<xsl:if test="post">
		<h3>Post(s)</h3>
		<ul><xsl:apply-templates select="post" /></ul>
	</xsl:if>
</xsl:template>

<xsl:template match="post">
	<li class="post"><a><xsl:attribute name="href"><xsl:value-of select="@href" /></xsl:attribute><xsl:value-of select="@href" /></a></li>
</xsl:template>
<xsl:template match="see">
	<li class="see"><a><xsl:attribute name="href">#<xsl:apply-templates /></xsl:attribute><code><xsl:apply-templates /></code></a></li>
</xsl:template>
<xsl:template match="author">
	<li class="author">
		<xsl:choose>
			<xsl:when test="@href">
				<a><xsl:attribute name="href"><xsl:value-of select="@href" /></xsl:attribute><xsl:apply-templates /></a>
			</xsl:when>
			<xsl:otherwise>
				<xsl:apply-templates />
			</xsl:otherwise>
		</xsl:choose>
	</li>
</xsl:template>
<xsl:template match="problem">
	<p><xsl:apply-templates /></p>
</xsl:template>
<xsl:template match="solution">
	<p><xsl:apply-templates /></p>
</xsl:template>

<xsl:template match="fixeslist"><xsl:apply-templates /></xsl:template>

<xsl:template match="fixes">
	<li class="fixes"><a><xsl:attribute name="href">#FIX_<xsl:apply-templates /></xsl:attribute><xsl:apply-templates /></a></li>
</xsl:template>

</xsl:stylesheet>

